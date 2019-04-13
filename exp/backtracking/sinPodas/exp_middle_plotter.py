import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
sns.set()

df = pd.read_csv("times_backtraking_sin_podas.csv")

# Nano -> Milli
df['time']  /= 1000000.0
df['teorica'] = 0.001*df['n'] * 2**(df['n'])

df.plot('n', ['time', 'teorica'])

ax1 = sns.lmplot(x='time', y='teorica', data=df);
plt.xlabel("T(n)");
plt.ylabel("cota(n)");

plt.show()
