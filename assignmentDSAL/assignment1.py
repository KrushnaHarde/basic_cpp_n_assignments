class sportsGroup:
    def __init__(self):
        self.cricket = []
        self.badminton = []
        self.football = []


    def duplicates(self,lst):
        result = []
        for item in lst:
            exists = False
            for res_item in result:
                if item == res_item:
                    exists = True
                    break
            if not exists:
                result += [item]
        return result

    def intersection(self,lst1,lst2):
        result = []
        for item in lst1:
            flag = 0
            for j in lst2:
                if item == j:
                    flag = 1
                    break
            if flag == 1:
                exists = False
                for res_item in result:
                    if item == res_item:
                        exists = True
                        break
                if not exists:
                    result += [item]
        return result

    def union(self,lst1,lst2):
        result = []
        for item in lst1:
            exists = False
            for res_item in result:
                if res_item == item:
                    exists = True
                    break
            if not exists:
                result += [item]
        for item in lst2:
            exists = False
            for res_item in result:
                if res_item == item:
                    exists = True
                    break
            if not exists:
                result += [item]
        return result

    def difference(self,lst1,lst2):
        result = []
        for item in lst1:
            flag = 0
            for j in lst2:
                if item == j:
                    flag = 1
                    break
            if flag == 0:
                exists = False
                for res_item in result:
                    if res_item == item:
                        exists = True
                        break
                if not exists:
                    result += [item]
        return result

    def length(self,lst):
        count = 0
        for _ in lst:
            count += 1
        return count

    def input(self):

        # a = int(input("Enter the number of student there in cricket:"))
        # for i in range (0,a):
        #     name = input("Enter the names of students who play cricket: ")
        #     self.cricket += [name]

        self.cricket += input(
            f"Enter the names of the {int(input('Enter the number of students who play cricket: '))} students, separated by spaces: ").split()

        # b = int(input("Enter the number of students there in badminton: "))
        # for i in range (0,b):
        #     name = input("Enter the names of students who play badminton: ")
        #     self.badminton += [name]

        self.badminton += input(
            f"Enter the names of the {int(input('Enter the number of students who play badminton: '))} students, separated by spaces: ").split()

        # c = int(input("Enter the number of student there in football:"))
        # for i in range (0,c):
        #     name = input("Enter the name of students who play football:")
        #     self.football += [name]

        self.football += input(f"Enter names of the {int(input('Enter no. of students who play football: '))} students, (space separated): ").split()


        # self.cricket = self.duplicates(self.cricket)
        # self.badminton = self.duplicates(self.badminton)
        # self.football = self.duplicates(self.football)

    def display(self):
        while(True):
            print("\nDetails: ")
            print("1. List of students who play both cricket and badminton: ")
            print("2. List of students who play either cricket or badminton not both: ")
            print("3. Number of students who play neither cricket nor badminton: ")
            print("4. Number of students who play cricket and football but not badminton: ")
            print("5. Exit. ")

            choice = input("Enter your choice: ")

            if choice == '1':
                cric_badm = self.intersection(self.badminton,self.cricket)
                print("List of students who play both cricket and badminton: ", cric_badm)

            elif choice == '2':
                cric_badm_union = self.union(self.cricket,self.badminton)
                cric_badm = self.intersection(self.cricket,self.badminton)
                cric_badm_nboth = self.difference(cric_badm_union,cric_badm)
                print("List of students who play either cricket or badminton not both: ",cric_badm_nboth)

            elif choice == '3':
                cric_badm_union = self.union(self.cricket,self.badminton)
                ncric_nbadm = self.difference(cric_badm_union,self.football)
                print("Number of students who play neither cricket nor badminton: ",self.length(ncric_nbadm))

            elif choice == '4':
                cric_foot = self.intersection(self.cricket,self.football)
                cric_foot_nbadm = self.difference(cric_foot,self.badminton)
                print("Number of students who play cricket and football but not badminton: ",self.length(cric_foot_nbadm))

            elif choice == '5':
                print("Exiting...")
                break

            else :
                print("Invalid choice!")


if __name__ == "__main__":
    sg = sportsGroup()
    sg.input()
    sg.display()

