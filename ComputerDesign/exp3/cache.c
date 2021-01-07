#include "common.h"

void mem_read(uintptr_t block_num, uint8_t *buf);
void mem_write(uintptr_t block_num, const uint8_t *buf);

typedef struct {
	union {
		union {
			bool valid	: 1; // Using 'Bit field' to explain the 'valid' is MSB.
			uint32_t tag;
		};
		uint32_t key_val;
	};
	bool dirty;

	uint8_t *sram;
} CacheLine;

#define CL_VALID 1
#define get_tag(val) ((val) & ~CL_VALID)

typedef struct {
	int associativity_width;

	uint32_t tag_mask;
	uint32_t set_mask;
	uint32_t offset_mask;

	CacheLine *line;
} Cache;


static Cache cache;

bool cache_query(Cache *c, uintptr_t addr, CacheLine **hit_cl) {
	/*
	TODO : check if cache is hit
	if hit
		use 'hit_cl' return the hitted CacheLine
		return true
	else
		use 'hit_cl' return a random CacheLine in cache
		return false
	*/
	return false;
}

CacheLine* cache_fetch(Cache *c, uintptr_t addr) {
	CacheLine *cl;
   	if( cache_query(c, addr, &cl) ) {
		hit_increase(1); //cache hit
		return cl;
	}

	// 

	/*
	TODO : 
	Now we get the random CacheLine, but whether it was modified? 
	How to judge it was modified?
	What to do when it was modified?
	*/

	return cl;
}

uint32_t cache_read(uintptr_t addr) {
	try_increase(1);
  	Cache *c = &cache;
	CacheLine *cl = cache_fetch(c, addr);

	uint32_t line_offset = (addr & ~0x3) & c->offset_mask;
	uint32_t *p = (void *)cl->sram + line_offset;
	return *p;
}

void cache_write(uintptr_t addr, uint32_t data, uint32_t wmask) {
	try_increase(1);
  	Cache *c = &cache;
	CacheLine *cl = cache_fetch(c, addr);

	uint32_t line_offset = (addr & ~0x3) & c->offset_mask;
	uint32_t *p = (void *)cl->sram + line_offset;

	*p = (*p & ~wmask) | (data & wmask);
	cl->dirty = true;
}

void init_cache(int total_size_width, int associativity_width) {
  Cache *c = &cache;
	int set_size_width = total_size_width - BLOCK_WIDTH - associativity_width;
	int nr_line = exp2(total_size_width - BLOCK_WIDTH);
	c->associativity_width = associativity_width;

	c->set_mask = mask_with_len(set_size_width) << BLOCK_WIDTH;
	c->offset_mask = mask_with_len(BLOCK_WIDTH);
	c->tag_mask = ~(c->set_mask | c->offset_mask);

	assert(exp2(associativity_width) <= nr_line);

	c->line = malloc(sizeof(CacheLine) * nr_line);

	int i;
	for(i = 0; i < nr_line; i ++) {
		c->line[i].key_val = 0;
		c->line[i].sram = malloc(BLOCK_SIZE);
	}
}
