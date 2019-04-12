import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
sns.set()

df = pd.read_csv("exp_dp_n50.csv")

# Nano -> Milli
df['time']  /= 1000000.0

ax = df.plot('n', ['time'], marker='o', title='Comparación de tiempos - Dinámica')
ax.set_xlabel('N')
ax.set_ylabel('Tiempos (ms)')

plt.show()