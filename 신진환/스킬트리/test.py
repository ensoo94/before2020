import unittest

from solution import solution

class TestSolution(unittest.TestCase):

    def test_case1(self):
        result = solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"])
        self.assertEqual(result, 2)
    
    def test_case2(self):
        result = solution("CBDE", ["C", "CBDE", "CD", "CED"])
        self.assertEqual(result, 2)

    def test_case3(self):
        result = solution("CBDE", ["CBDE"])
        self.assertEqual(result, 1)
        
if __name__ == "__main__":
    unittest.main()