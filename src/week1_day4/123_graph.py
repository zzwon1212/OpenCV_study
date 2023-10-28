import matplotlib.pyplot as plt
import numpy as np

def graph(x, y, color, title):
    plt.plot(x, x, linestyle='dashed', color='black')
    plt.plot(x, y, linewidth=3, color=color)

    plt.xlim(-5, 260)
    plt.ylim(-5, 260)
    plt.xticks([0, 128, 255])
    plt.yticks([0, 128, 255])

    plt.xlabel('Input Pixel')
    plt.ylabel('Output Pixel')
    plt.title(title)

x = np.arange(256)



# 1 감마 조절, 이진화
plt.figure(figsize=(10, 5))

plt.subplot(121)
brightness = (x / 255) ** 0.5 * 255
graph(x, brightness, "green", "Gamma Correction")

plt.subplot(122)
binary = [255 if i > 255 / 2 else 0 for i in x]
graph(x, binary, "purple", "Binarization")

plt.show()



# 2 밝기 조절
plt.figure(figsize=(10, 5))

plt.subplot(121)
decreasing = [0 if i - 50 <= 0 else i - 50 for i in x]
graph(x, decreasing, "blue", "Decreasing Brightness")

plt.subplot(122)
increasing = [255 if i + 50 >= 255 else i + 50 for i in x]
graph(x, increasing, "red", "Increasing Brightness")

plt.show()



# 3 반전
plt.figure(figsize=(6, 5))
y = 255 - x
graph(x, y, "brown", "Inverting")
plt.show()



# 4 간단한 명암비 조절
plt.figure(figsize=(10, 5))

plt.subplot(121)
decreasing = x * 0.5
graph(x, decreasing, "blue", "Decreasing Contrast")
plt.text(20, 230, r'$s = 0.5$', fontsize=16, color="black")

plt.subplot(122)
increasing = [255 if i * 2 >= 255 else i * 2 for i in x]
graph(x, increasing, "red", "Increasing Contrast")
plt.text(20, 230, r'$s = 2$', fontsize=16, color="black")

plt.show()



# 5 (조금) 효과적인 명암비 조절
plt.figure(figsize=(10, 5))

plt.subplot(121)
decreasing = x + (x - 128) * -0.5
graph(x, decreasing, "blue", "Decreasing Contrast")
plt.text(20, 230, r'$\alpha = -0.5$', fontsize=16, color="black")

plt.subplot(122)
increasing = x + (x - 128) * 1.0
for i in range(len(increasing)):
    if increasing[i] < 0:
        increasing[i] = 0
    elif increasing[i] > 255:
        increasing[i] = 255
    else:
        pass
graph(x, increasing, "red", "Increasing Contrast")
plt.text(20, 230, r'$\alpha = 1.0$', fontsize=16, color="black")

plt.show()



# 6 평균 밝기를 고려한 명암비 조절
plt.figure(figsize=(10, 5))

plt.subplot(121)
decreasing = x + (x - 84) * 1.0
for i in range(len(decreasing)):
    if decreasing[i] < 0:
        decreasing[i] = 0
    elif decreasing[i] > 255:
        decreasing[i] = 255
    else:
        pass
graph(x, decreasing, "blue", "Contrast Control(Low Mean)")
plt.xticks([0, 84, 255])
plt.yticks([0, 84, 255])
plt.text(20, 230, r'$\alpha = 1.0$', fontsize=16, color="black")

plt.subplot(122)
increasing = x + (x - 211) * 1.0
for i in range(len(increasing)):
    if increasing[i] < 0:
        increasing[i] = 0
    elif increasing[i] > 255:
        increasing[i] = 255
    else:
        pass
graph(x, increasing, "red", "Contrast Control(High Mean)")
plt.xticks([0, 211, 255])
plt.yticks([0, 211, 255])
plt.text(20, 230, r'$\alpha = 1.0$', fontsize=16, color="black")

plt.show()
