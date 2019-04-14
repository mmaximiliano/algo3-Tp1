import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

def teorica(x):
	return 0.001*x*np.float_power(2,(x/2))

df = pd.read_csv("times_middle.csv")

# Nano -> Milli
df['time']  /= 1000000.0
df['teorica'] = 0.00004*df['n'] * 2**(df['n'] / 2.0) 


df.plot('n', ['time', 'teorica'])

r = np.corrcoef(df['time'], df['teorica'])[0,1]
print(r)
#out: r = 0.9999865200267454

ax1 = sns.lmplot(x='time', y='teorica', data=df);
plt.xlabel("T(n)");
plt.ylabel("cota(n)");

#ax = df.plot('n', ['time'], marker='o', title='Comparación de tiempos - Meet In The Middle')
# plt.plot('n', teorica(['n']), color='coral')
#ax.set_xlabel('N')
#ax.set_ylabel('Tiempos (ms)')

plt.show()

