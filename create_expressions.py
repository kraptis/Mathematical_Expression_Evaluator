import sys
import random

# dictionary of operator precedence and incidence probability, with an
# evaluator added just for fun.
operators = {
    '%': {'prec': 20, 'prob': .15, 'eval': lambda a, b: a%b},
    '*': {'prec': 20, 'prob': .3, 'eval': lambda a, b: a*b},
    '/': {'prec': 20, 'prob': .15, 'eval': lambda a, b: a/b},
    '+': {'prec': 30, 'prob': .2, 'eval': lambda a, b: a+b},
    '-': {'prec': 30, 'prob': .2, 'eval': lambda a, b: a-b}}

max_levels = 10
integer_range = (-10000, 10000)
random.seed()

# A node in an expression tree
class expression(object):
    def __init__(self):
        super(expression, self).__init__()

    def precedence(self):
        return -1

    def eval(self):
        return 0

    @classmethod
    def create_random(cls, level):
        if level == 0:
            is_op = True
        elif level == max_levels:
            is_op = False
        else:
            is_op = random.random() <= 1.0 - pow(level/max_levels, 2.0)

        if is_op:
            return binary_expression.create_random(level)
        else:
            return integer_expression.create_random(level)

class integer_expression(expression):
    def __init__(self, value):
        super(integer_expression, self).__init__()

        self.value = value

    def __str__(self):
        return self.value.__str__()

    def precedence(self):
        return 0

    def eval(self):
        return self.value

    @classmethod
    def create_random(cls, level):
        return integer_expression(random.randint(integer_range[0],
                                                 integer_range[1]))

class binary_expression(expression):
    def __init__(self, symbol, left_expression, right_expression):
        super(binary_expression, self).__init__()

        self.symbol = symbol
        self.left = left_expression
        self.right = right_expression

    def eval(self):
        f = operators[self.symbol]['eval']
        return f(self.left.eval(), self.right.eval())

    @classmethod
    def create_random(cls, level):
        symbol = None

        # Choose an operator based on its probability distribution
        r = random.random()
        cumulative = 0.0
        for k, v in operators.items():
            cumulative += v['prob']
            if r <= cumulative:
                symbol = k
                break

        assert symbol != None

        left = expression.create_random(level + 1)
        right = expression.create_random(level + 1)

        return binary_expression(symbol, left, right)

    def precedence(self):
        return operators[self.symbol]['prec']

    def __str__(self):
        left_str = self.left.__str__()
        right_str = self.right.__str__()
        op_str = self.symbol

        # Use precedence to determine if we need to put the sub expressions in
        # parentheses
        if self.left.precedence() > self.precedence():
            left_str = '('' '+left_str+' '')'
        if self.right.precedence() > self.precedence():
            right_str = '('' '+right_str+' '')'

        # Nice to have space around low precedence operators
       # if operators[self.symbol]['prec'] >= 30:
        op_str = ' ' + op_str + ' '

        return left_str + op_str + right_str

max_result = pow(10, 10)
text_file = open("expressions.txt", "w")
for i in range(5):
    expr = expression.create_random(0)

    try:
        value = float(expr.eval())
    except:
        value = 'indeterminate'

    print expr#, '=', value

    
    text_file.write("%s\n" % expr)


text_file.write("QUIT")
text_file.close()


