import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

#grafico complejidad de exp
df = pd.read_csv("bt_dp_100.csv")
# Nano -> Milli
df['BT']  /= 1000000.0
df['DP']  /= 1000000.0

df.plot('n', ['BT', 'DP'])

ax1 = sns.lmplot(x='BT', y='DP', data=df);
plt.xlabel("Backtracking");
plt.ylabel("Dinamica");

plt.show()


#grafico complejidad de exp
df = pd.read_csv("bt_dp_10000.csv")
# Nano -> Milli
df['BT']  /= 1000000.0
df['DP']  /= 1000000.0

df.plot('n', ['BT', 'DP'])

ax1 = sns.lmplot(x='BT', y='DP', data=df);
plt.xlabel("Backtracking");
plt.ylabel("Dinamica");

plt.show()
