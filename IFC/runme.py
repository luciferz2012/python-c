from module3 import openModelBN, closeModel, getSPFFHeaderItem

id = openModelBN("house.ifc", "ifc4.exp")
print(id)
print(getSPFFHeaderItem(id, 9, 0))
closeModel(id)