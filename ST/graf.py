import re
import numpy as np
import matplotlib.pyplot as plt
fname = input('Enter file name: ')
if len(fname) < 1 : fname = "dbible.txt"

try:
    fh = open(fname)
except:
    print('File connot be opened', fname)
    quit()
f = open("mediabible", 'w')
tempos = list()
media = list()
i = 0
for a in range(6):
    tempos.append(0)
# counts = dict()
for line in fh:
    tempos[i%6] = tempos[i%6] + float(line)
    i = i + 1

for tempo in tempos:
    media.append(tempo/5);
for m in media:
    f.write(str(m)+'\n')
f.close()



# fig = plt.figure()
# ax = fig.add_axes([0,0,1,1])
# langs = ['ABB', 'ARN', 'HASH', 'MTF', 'LP', 'TRIES']
# ax.bar(langs,media)
# plt.show()


# Make a fake dataset:
# height = [3, 12, 5, 18, 45]
bars = ['ABB', 'ARN', 'HASH', 'MTF', 'LP', 'TRIES']
y_pos = np.arange(len(bars))

# Create bars
plt.bar(y_pos, media)

# Create names on the x-axis
plt.xticks(y_pos, bars)

plt.title('bible.txt')

# Show graphic
plt.show()

# fig = plt.figure()
# ax = fig.add_axes([0,0,1,1])
# langs = ['C', 'C++', 'Java', 'Python', 'PHP']
# students = [23,17,35,29,12]
# ax.bar(langs,students)
# plt.show()
