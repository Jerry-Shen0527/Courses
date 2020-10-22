import taichi as ti
import numpy as np

ti.init(arch=ti.gpu)

# 显式积分器，弹簧质点系统

for frame in range(20000):
    gui.clear(0x112F41)
    advect()
    pos_ = pos.to_numpy()
    pos_ = np.reshape(pos_, (num*num, 2))
    gui.circles(pos_, radius=10, color=0x068587)
    gui.show()


