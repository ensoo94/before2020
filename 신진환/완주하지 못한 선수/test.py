import unittest

from solution import solution

class TestSolution(unittest.TestCase):

    def test_case1(self):
        result = solution(["leo", "kiki", "eden"], ["eden", "kiki"])
        self.assertEqual(result, "leo")
    
    def test_case2(self):
        result = solution(["marina", "josipa", "nikola", "vinko", "filipa"], ["josipa", "filipa", "marina", "nikola"])
        self.assertEqual(result, "vinko")

    def test_case3(self):
        result = solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "mislav", "ana"])
        self.assertEqual(result, "mislav")
        
if __name__ == "__main__":
    unittest.main()