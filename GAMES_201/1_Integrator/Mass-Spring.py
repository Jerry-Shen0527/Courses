import taichi as ti
import numpy as np

ti.init(arch=ti.gpu)

# 显式积分器，弹簧质点系统

dim = 2
num = 10
mass = 1.0
length = 1.0/num
k = 100

dt = 0.01

pos = ti.Vector(dim, dt=ti.f32, shape=(num, num))
velocity = ti.Vector(dim, dt=ti.f32, shape=(num, num))
force = ti.Vector(dim, dt=ti.f32, shape=(num, num))


@ti.kernel
def initialize():
    dx = 1/(num-1)
    for i in range(num):
        for j in range(num):
            pos[i, j][0] = i*dx
            pos[i, j][1] = j*dx


@ti.func
def judge(i, j) -> ti.i16:
    result = 0
    if i >= 0 and i < num and j >= 0 and j < num:
        result = 1
    return result


@ti.func
def calc_force():
    for i in range(num):
        for j in range(num):
            force[i,j][0]=0
            force[i,j][1]=-mass*1
            # 最上方一排格点不动

            # 遍历临近的格点，认为相连
            for adj_i in range(i-1, i+2):
                for adj_j in range(j-1, j+2):
                    if judge(adj_i, adj_j) == 1:
                        dis_vec = pos[adj_i, adj_j]-pos[i, j]
                        dis_len = ti.sqrt(
                            dis_vec.x*dis_vec.x+dis_vec.y*dis_vec.y)
                        dis_vec /= dis_len
                        if (adj_i+adj_j-i-j) % 2 == 0:
                            if adj_j != j and adj_i != i:
                                force[i, j] += (dis_len -
                                                ti.sqrt(2)*length)*dis_vec*k
                        else:
                            force[i, j] += (dis_len-length)*dis_vec*k
            if j == 9:
                force[i, j][0]=0
                force[i, j][1]=0



@ ti.kernel
def advect_explicit():
    for i in range(num):
        for j in range(num):
            pos[i, j] += velocity[i, j]*dt
    calc_force()
    for i in range(num):
        for j in range(num):
            velocity[i, j] += force[i, j]/mass*dt

@ti.kernel
def advect_semi_implicit():
    calc_force()
    for i in range(num):
        for j in range(num):
            velocity[i, j] += force[i, j]/mass*dt
    for i in range(num):
        for j in range(num):
            pos[i, j] += velocity[i, j]*dt

# @ti.kernel
# def advect_implicit():
    

  

initialize()
gui = ti.GUI('Window Title', (512, 512))

for frame in range(20000):
    gui.clear(0x112F41)
    advect_semi_implicit()
    pos_ = pos.to_numpy()
    pos_ = np.reshape(pos_, (num*num, 2))
    gui.circles(pos_, radius=10, color=0x068587)
    gui.show()


