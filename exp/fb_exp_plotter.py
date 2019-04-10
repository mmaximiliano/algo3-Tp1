import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
sns.set()

df = pd.read_csv("stairs_time.csv")

# Nano -> Milli
df['TopDown']   /= 1000000.0
df['BottomUp']  /= 1000000.0
df['BottomUp2'] /= 1000000.0

ax = df.plot('n', ['TopDown', 'BottomUp', 'BottomUp2'], marker='o', title='Comparación de tiempos - Dinámica')
ax.set_xlabel('N')
ax.set_ylabel('Tiempos (ms)')

plt.show()