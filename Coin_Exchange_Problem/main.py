# find the least amount of coin needed to make the given change
# example : for given amount 6
#          and the following denomination [ 1,3,4]
# answer will be 2 (two 3 coins)


class CoinExchange:
    def __init__(self):
        self.amount = 6  # exchange amount
        self.change = [1, 3, 4]  # coin denomination list
        self.container = []
        self.container.append(0)
        for i in range(1, self.amount+1):
            self.container.append(self.amount+1)
        self.getWays()
        print(self.container[-1])

    def getWays(self):
        for i in range(1, self.amount+1):
            for j in self.change:
                if i >= j:
                    # get ways
                    prevIndex = i-j
                    prevVal = self.container[prevIndex] + 1
                    self.container[i] = min(prevVal, self.container[i])


CoinExchange()
