import csv
from statistics import *
import numpy as np
import matplotlib.pyplot as plt


#INFO:
#intestazione CSV: matr,p1,p2,p3,tot,voto

with open('ranking.csv', mode='r') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    line_count = 0
    dati={}
    voti={}
    for row in csv_reader:
        if line_count == 0:
            print(f'I nomi delle colonne sono {", ".join(row)}')
            line_count += 1
        print(f'\t{row["matr"]} ha ottenuto i punti {row["p1"]}  {row["p2"]}  {row["p3"]} per un totale di  {row["tot"]} punti. Voto: {row["voto"]}.')
        line_count += 1
        dati[row["matr"]]=float(row["tot"])
        if row["voto"]=="":
            voti[row["matr"]]=float(17)
        else:
            voti[row["matr"]]=float(row["voto"])
    print(f'{line_count} linee processate.')

#it=iter(dati)
#for matr in it:
#    print(dati[matr])

mu=mean(dati.values())
sigma=stdev(dati.values())

print("mean_punti",mu)
print("std_punti",sigma)

gaussian = np.random.normal(mu,sigma, 1000)

#print(gaussian)

plt.figure()
count, bins, ignored = plt.hist(gaussian, 30, density=True)
plt.plot(bins, 1/   (sigma * np.sqrt(2 * np.pi)) * np.exp( - (bins - mu)**2 / (2 * sigma**2) ) ,linewidth=2, color='r')
plt.title("distribuzione dei punteggi")
#plt.show()
plt.savefig("scores distribution")


#distribuzione dei voti
mu=mean(voti.values())
sigma=stdev(voti.values())

print("mean_voti",mu)
print("mean_voti",sigma)

plt.figure()
gaussian = np.random.normal(mu,sigma, 1000)
count, bins, ignored = plt.hist(gaussian, 30, density=True)
plt.plot(bins, 1/ (sigma * np.sqrt(2 * np.pi)) * np.exp( - (bins - mu)**2 / (2 * sigma**2) ) ,linewidth=2, color='r')
plt.title("distribuzione dei voti")
#plt.show()
plt.savefig("marks distribution")

