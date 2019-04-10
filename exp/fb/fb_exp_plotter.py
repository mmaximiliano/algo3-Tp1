import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
sns.set()

df = pd.read_csv("times_fuerzaBruta.csv")

# Nano -> Milli
df['time']   /= 1000000.0

ax = df.plot('n', ['times'], marker='o', title='Comparación de tiempos - Fuerza Bruta')
ax.set_xlabel('N')
ax.set_ylabel('Tiempos (ms)')

plt.show()