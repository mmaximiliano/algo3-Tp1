import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

df = pd.read_csv("times_bt_podas_mejor_caso.csv")
df_p = pd.read_csv("times_bt_podas_peor_caso.csv")

# Nano -> Milli
df['time']  /= 1000000.0
df_p['time']  /= 1000000.0
df['peor'] = df_p['time']

df.plot('n', ['time', 'peor'], title='Mejor vs Peor')

r = np.corrcoef(df['time'], df['peor'])[0,1]
print(r)
#out: r = 0.9366349410059747

ax1 = sns.lmplot(x='time', y='peor', data=df);
plt.xlabel("N");
plt.ylabel("tiempo");

plt.show()
