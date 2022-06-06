type_names = []
tab_cells = []

with open("test.txt", "r") as file:
    lines = file.readlines()
    for index, line in enumerate(lines):
        cells = line.split('\t')
        if index == 2:
            type_names = cells
        if index > 2:
            tab_cells.append(cells)

print(type_names)
print(tab_cells)

for cells in tab_cells:
    line_index = 0
    for index, cell in enumerate(cells):
        if index == 0:
            line_index = cell
        else:
            if cell != " " and cell != " \n":
                action_type = ""
                action_value = ""
                if cell[0] == "s":
                    action_type = "ACTION::SWAP"
                    action_value = cell[1:]
                elif cell[0] == "r":
                    action_type = "ACTION::REPLACE"
                    action_value = cell[1:]
                elif cell == "acc":
                    action_type ="ACTION::ACC"
                    action_value = 0
                else:
                   action_type = "ACTION::GOTO"
                   action_value = cell
                print(f"syntaxAnalyzer.lrTable[{line_index}][\"{type_names[index - 1]}\"]", "= actionState{", f"{action_type}, {action_value}", "};")
                # print(line_index, type_names[index - 1])