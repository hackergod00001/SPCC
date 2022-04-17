import re
s = input("Enter filename : ")
f = open(s, 'r')
text = f.read()
operators = ['+', '-', '*', '/', '=', '+=', '-=', '==', '<', '>', '<=', '>=']
keywords = ['auto','break', 'case', 'char', 'const', 'continue', 'default', 'do','double', 'else', 'enum', 'extern', 'float', 'for', 'goto', 'if','int', 'long', 'register', 'return', 'short', 'signed', 'sizeof', 'static','struct', 'switch', 'typedef', 'union', 'unsigned', 'void', 'volatile', 'while']
Specialsymbols = [' ', ' ', '.', ',', '\n', ';', '(', ')', '<', '>', '{', '}', '[', ']','!', '@', '#', '$', '&', '^', '*']
in_keywords = []
in_spl_symbols = []
in_operators = []
in_constants = []
in_invalidconstants = []
in_Specialsymbols = []
in_identifiers = []
tokens = []
isStr = False
isWord = False
isCmt = 0
token = ''
for i in text:
    if i == '/':
        isCmt = isCmt+1
    elif isCmt == 2:
        if i == '\n':
            token = ''
            isCmt = 0
    elif i == '"' or i == "'":
        if isStr:
            tokens.append(token)
            token = ''
        isStr = not isStr
    elif isStr:
        token = token+i
    elif i.isalnum() and not isWord:
        isWord = True
        token = i
    elif (i in Specialsymbols) or (i in operators):
        if token:
            tokens.append(token)
            token = ''
        if not (i==' ' or i=='\n' or i==' '):
            tokens.append(i)
    elif isWord:
        token = token+i
    elif i == '%':
        print("Invalid Operators\n")
for token in tokens:
    if token in operators:
        in_operators.append(token)
    elif token in keywords:
        in_keywords.append(token)
    elif re.search("^[_a-zA-Z][_a-zA-Z0-9]*$",token):
        in_identifiers.append(token)
    elif token in Specialsymbols:
        in_Specialsymbols.append(token)
    elif re.search("^[0-9]*$",token):
        in_constants.append(token)
    else:
        in_invalidconstants.append(token)
print("No of tokens = ", len(tokens))
print("\nNo. of keywords = ",len(in_keywords))
print(in_keywords);
print("\nNo. of oparators = ",len(in_operators))
print(in_operators);
print("\nNo. of identifiers = ",len(in_identifiers))
print(in_identifiers);
print("\nNo. of constants = ",len(in_constants))
print(in_constants);
print("\nNo. of Invalid tokens = ",len(in_invalidconstants))
print(in_invalidconstants);
print("\nNo. of Specialsymbols = ",len(in_Specialsymbols))
print(in_Specialsymbols);
f.close()