import ast
import sys
import json


def parse_file(filename):
    with open(filename, "r") as file:
        tree = ast.parse(file.read(), filename=filename)
    return tree


def get_access_specifier(method_name):
    if method_name.startswith("__") and not method_name.endswith("__"):
        return "private"
    elif method_name.startswith("_"):
        return "protected"
    else:
        return "public"


def get_class_relationships(tree):
    class_relations = []
    for node in ast.walk(tree):
        if isinstance(node, ast.ClassDef):
            class_info = {
                "class_name": node.name,
                "bases": [base.id for base in node.bases if isinstance(base, ast.Name)],
                "methods": [
                    {"name": n.name, "access_specifier": get_access_specifier(n.name)}
                    for n in node.body
                    if isinstance(n, ast.FunctionDef)
                ],
            }
            class_relations.append(class_info)
    return class_relations


if __name__ == "__main__":
    filename = sys.argv[1]
    tree = parse_file(filename)
    class_relationships = get_class_relationships(tree)
    print(json.dumps(class_relationships, indent=4))
