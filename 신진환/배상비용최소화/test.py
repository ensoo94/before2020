import unittest

from solution import solution

class TestSolution(unittest.TestCase):

    def test_case1(self):
        result = solution(4, [4, 3, 3])
        self.assertEqual(result, 12)
    
    def test_case2(self):
        result = solution(3, [3, 3, 3])
        self.assertEqual(result, 12)

    def test_case3(self):
        result = solution(10, [5, 2, 10])
        self.assertEqual(result, 17)
        
if __name__ == "__main__":
    unittest.main()