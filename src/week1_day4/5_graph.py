import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

def graph(x, y, color, title):
    plt.figure(figsize=(5, 5))

    plt.plot(x, x, linestyle='dashed', color='black')
    plt.plot(x, y, linewidth=3, color=color)

    plt.xlim(-5, 260)
    plt.ylim(-5, 260)
    plt.xticks([0, 255])
    plt.yticks([0, 255])

    plt.xlabel('Input Grayscale Value')
    plt.ylabel('Output Grayscale Value')
    plt.title(title)

x = np.arange(256)



# # 1. lenna hist stretching
# plt.figure(figsize=(5, 5))
# y = []
# for i in x:
#     v = (i - 25) / (245 - 25) * 255
#     if v < 0:
#         v = 0
#     elif v > 255:
#         v = 255
#     y.append(v)
# (x - 25) / (245 - 25) * 255
# graph(x, y, "blue", "Histogram Stretching Function")
# print(y)
# plt.show()




# 2. lenna hist equalization
lenna_freq = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 6, 20, 29, 59, 97, 137, 181, 220, 300, 421, 500, 613, 760, 940, 1061, 1254, 1442, 1647, 1762, 1881, 1998, 2093, 2020, 2103, 2086, 2031, 1979, 1807, 1732, 1668, 1578, 1469, 1276, 1238, 1220, 999, 934, 975, 881, 889, 791, 798, 771, 779, 852, 820, 831, 786, 878, 909, 869, 853, 947, 972, 907, 913, 864, 935, 934, 967, 1009, 1016, 1062, 1132, 1123, 1188, 1220, 1323, 1401, 1538, 1619, 1808, 1870, 2087, 1894, 1932, 1956, 1836, 1762, 1729, 1612, 1504, 1434, 1367, 1362, 1344, 1345, 1451, 1358, 1356, 1384, 1448, 1567, 1572, 1604, 1777, 1817, 1893, 2029, 2141, 2304, 2321, 2368, 2522, 2306, 2304, 2252, 2078, 1992, 1822, 1933, 1903, 2025, 2136, 2261, 2303, 2327, 2453, 2459, 2408, 2236, 2316, 2287, 2174, 2283, 2316, 2392, 2595, 2687, 2745, 2701, 2555, 2411, 2261, 2041, 1852, 1780, 1615, 1473, 1425, 1352, 1234, 1254, 1195, 1170, 1208, 1342, 1263, 1233, 1158, 1186, 1225, 1085, 943, 905, 822, 785, 689, 609, 630, 644, 678, 635, 663, 739, 795, 830, 941, 905, 976, 920, 910, 843, 822, 870, 902, 834, 886, 908, 970, 977, 1065, 1042, 1069, 956, 982, 954, 865, 697, 544, 491, 393, 381, 284, 230, 234, 195, 188, 125, 77, 74, 59, 51, 22, 19, 9, 7, 6, 8, 1, 0, 0, 1, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
lenna_hist = dict(zip(x, lenna_freq))

# # 데이터를 키로 정렬합니다.
# lenna_hist = dict(sorted(lenna_hist.items()))

# 누적 빈도수 계산
cdf = [sum(list(lenna_hist.values())[:i+1])/sum(lenna_hist.values())*255 for i in range(len(lenna_hist))]

# CDF 그래프 그리기
graph(list(lenna_hist.keys()), cdf, color='red', title='Histogram Equalization')
plt.xlabel('Input Grayscale Value')
plt.ylabel('Output Grayscale Value')
# plt.grid(True)

plt.show()

