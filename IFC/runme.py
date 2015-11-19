from module3 import openModel, closeModel

id = openModel("house.ifc", "ifc2x3_tc1.exp")
print(id)
closeModel(id)