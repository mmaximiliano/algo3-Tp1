import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

#grafico complejidad real
x = np.arange(30)
y = x*np.power(2,x)
plt.plot(x,y)


#grafico complejidad de exp
df = pd.read_csv("times_fuerzaBruta_n30.csv")

# Nano -> Milli
df['time']  /= 1000000.0

ax = df.plot('n', ['time'], marker='o', title='Comparación de tiempos - Dinámica')
ax.set_xlabel('N')
ax.set_ylabel('Tiempos (ms)')



plt.show()