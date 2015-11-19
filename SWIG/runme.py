from ifc import sdaiOpenModelBN, sdaiCloseModel

id = sdaiOpenModelBN(0, 'house.ifc', 'IFC2X3_TC1.exp')
print(id)
sdaiCloseModel(id)