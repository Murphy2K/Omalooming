#See programm arvutab ülaframuugi prosside vahed ühtlaselt jaotades.
Pikkus = int(input("Anna framuugi pikkus mm: "))
r = int(input("Mitu R on: "))
mitu = r - 1 
#print(Pikkus, mitu)
x = 26 #kaika paksus (termo 26, tava 29)
ava = Pikkus - (2*x)
print("Arvutan valgusava. ", Pikkus, " - 28 mm = ", ava)
prossi_vahed = ava / (mitu + 1)
print("Prosside vahed peaks olema: ", round(prossi_vahed, 2))
print("Framuugi servast mõõtes prossede keskkohad:")
a = prossi_vahed + x
for x in range (mitu):
    print(x+1, ". Prossi keskele on: ",round(a, 2))
    a = a + prossi_vahed
       