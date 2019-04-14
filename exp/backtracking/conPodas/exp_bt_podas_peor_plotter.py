import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

df = pd.read_csv("times_bt_podas_peor_caso.csv")

# Nano -> Milli
df['time']  /= 1000000.0
df['teorica'] = 0.0000000001*df['n'] * 2**(df['n'])

df.plot('n', ['time', 'teorica'], title='Podas peor')

r = np.corrcoef(df['time'], df['teorica'])[0,1]
print(r)
#out: r = -0.07961647541318055

ax1 = sns.lmplot(x='time', y='teorica', data=df);
plt.xlabel("T(n)");
plt.ylabel("cota(n)");

plt.show()
