import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
sns.set()

df = pd.read_csv("times_bt_podas_mejor_caso.csv")
df_p = pd.read_csv("times_bt_podas_peor_caso.csv")

# Nano -> Milli
df['time']  /= 1000000.0
df_p['time']  /= 1000000.0
df['peor'] = df_p['time']

df.plot('n', ['time', 'peor'], title='Mejor vs Peor')


ax1 = sns.lmplot(x='time', y='peor', data=df);
plt.xlabel("N");
plt.ylabel("tiempo");

plt.show()
