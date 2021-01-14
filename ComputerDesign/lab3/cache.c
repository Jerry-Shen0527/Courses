#include "common.h"

void mem_read(uintptr_t block_num, uint8_t* buf);
void mem_write(uintptr_t block_num, const uint8_t* buf);

typedef struct {
	union {
		union {
			bool valid : 1; // Using 'Bit field' to explain the 'valid' is MSB.
			uint32_t tag;
		};
		uint32_t key_val;
	};
	bool dirty;

	uint8_t* sram;
} CacheLine;

#define CL_VALID 1
#define get_tag(val) ((val) & ~CL_VALID)

typedef struct {
	int associativity_width;

	uint32_t tag_mask;
	uint32_t set_mask;
	uint32_t offset_mask;

	CacheLine* line;
} Cache;

static Cache cache;

bool cache_query(Cache* c, uintptr_t addr, CacheLine** hit_cl) {
	/*
	TODO : check if cache is hit
	if hit
		use 'hit_cl' return the hitted CacheLine
		return true
	else
		use 'hit_cl' return a random CacheLine in cache
		return false
	*/
	uint32_t tag = addr & c->tag_mask;
	int N = exp2(c->associativity_width);
	int set_index = N * (c->set_mask & addr) >> BLOCK_WIDTH;

	for (int i = 0; i < N; ++i)
	{
		if (c->line[i + set_index].valid)
		{
			uint32_t cache_tag = get_tag(c->line[i + set_index].tag);

			if (tag == cache_tag)
			{
				*hit_cl = &(c->line[i + set_index]);
				return true;
			}
		}
	}

	*hit_cl = &(c->line[rand() % N + set_index]);

	return false;
}

CacheLine* cache_fetch(Cache* c, uintptr_t addr) {
	CacheLine* cl;
	if (cache_query(c, addr, &cl)) {
		hit_increase(1); //cache hit

		return cl;
	}

	/*
	TODO :
	Now we get the random CacheLine, but whether it was modified?
	How to judge it was modified?
	What to do when it was modified?
	*/

	if (cl->dirty)
	{
		int set_index = (addr & c->set_mask);

		mem_write((set_index | get_tag(cl->tag)) >> BLOCK_WIDTH, cl->sram);
	}
	mem_read(addr >> BLOCK_WIDTH, cl->sram);

	cl->tag = c->tag_mask & addr;
	cl->valid = true;
	cl->dirty = false;

	return cl;
}

uint32_t cache_read(uintptr_t addr) {
	try_increase(1);
	Cache* c = &cache;
	uint32_t line_offset = (addr & ~0x3) & c->offset_mask;
	CacheLine* cl = cache_fetch(c, addr);
	//Usage of void* is forbidden in ANSI C. Here replacing it with unsigned char.
	uint32_t* p = (uint8_t*)cl->sram + line_offset;
	return *p;
}

void cache_write(uintptr_t addr, uint32_t data, uint32_t wmask) {
	try_increase(1);
	Cache* c = &cache;
	uint32_t line_offset = (addr & ~0x3) & c->offset_mask;
	CacheLine* cl = cache_fetch(c, addr);

	uint32_t* p = (uint8_t*)cl->sram + line_offset;

	*p = (*p & ~wmask) | (data & wmask);
	cl->dirty = true;
}

void init_cache(int total_size_width, int associativity_width) {
	Cache* c = &cache;

	//14 width in total, 6 for sets, which means 2^6
	int set_size_width = total_size_width - BLOCK_WIDTH - associativity_width;
	int nr_line = exp2(total_size_width - BLOCK_WIDTH);
	c->associativity_width = associativity_width;

	//111111000000
	c->set_mask = mask_with_len(set_size_width) << BLOCK_WIDTH;

	//111111
	c->offset_mask = mask_with_len(BLOCK_WIDTH);

	//11111111111111111111000000000000
	c->tag_mask = ~(c->set_mask | c->offset_mask);

	assert(exp2(associativity_width) <= nr_line);

	c->line = malloc(sizeof(CacheLine) * nr_line);

	int i;
	for (i = 0; i < nr_line; i++) {
		c->line[i].key_val = 0;//Set both tag and valid 0
		c->line[i].sram = malloc(BLOCK_SIZE);
		c->line[i].dirty = false;
	}
}