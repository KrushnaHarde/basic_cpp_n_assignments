# In second year computer engineering class, group A student’s
# play cricket, group B students play badminton and group C
# students play football.
# Write a Python program using functions to compute
# following: -  a) List of students who play both cricket and
# badminton  b) List of students who play either cricket or
# badminton but not both  c) Number of students who play
# neither cricket nor badminton d) Number of students who
# play cricket and football but not badminton. (Note- While
# realizing the group, duplicate entries should be avoided, Do
# not use SET built-in functions)

class Sports:
    def __init__(self):
        self.cricket = []
        self.badminton = []
        self.football = []

    def duplicates(self, list):
        '''This function will remove the duplicates element from list'''
        result = []
        for item in list:
            isExist = False
            for res in result:
                if res == item:
                    isExist = True
                    break
            if not isExist:
                result += item
        return result

    def intersection(self, list1, list2):
        result = []
        for item1 in list1:
            for item2 in list2:
                if item1 == item2:
                    result += item1
                    break
        return result

    def union(self, list1, list2):
        result = []
        for item in list1:
            result += item  # copying item of list1 to result

        for item in list2:
            exist = False
            for res in result:
                if item == res:
                    exist = True
                    break
            if not exist:
                result += item
        return result

    def difference(self, list1, list2):
        #   elements in list1 which is not present in list2
        result = []
        for item1 in list1:
            exist = False
            for item2 in list2:
                if item1 == item2:
                    exist = True
                    break
            if not exist:
                result += item1
        return result

    def crickAndBad(self):
        crickAndBad = self.intersection(self.cricket, self.badminton)
        print(crickAndBad)
        return crickAndBad

    def crickOrBad(self):
        cab = self.intersection(self.cricket, self.badminton)
        corb = self.union(self.cricket, self.badminton)
        res = self.difference(corb, cab)
        print(res)
        return res

    def norCrikBad(self):
        corb = self.union(self.cricket, self.badminton)
        res = self.difference(self.football, corb)
        return len(res)

    def crickFootButnoBad(self):
        caf = self.intersection(self.cricket, self.football)
        res = self.difference(caf, self.badminton)
        return len(res)


    def input(self):
        self.cricket += self.duplicates(input(f"Enter name of Students for cricket: ").split())
        self.badminton += self.duplicates(input("Enter name of students for badminton: ").split())
        self.football += self.duplicates(input("Enter name of students for football: ").split())

        print(self.cricket,  "\t", self.badminton, '\t', self.football)


if __name__ == "__main__":
    obj = Sports()
    obj.input()
    obj.crickAndBad()
    obj.crickOrBad()
    print("Number of students who play neither cricket nor badminton: ", obj.norCrikBad())
    # print()
    print('Number of students who play cricket and football but not badminton: ', obj.crickFootButnoBad())
    # print()