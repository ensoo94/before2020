import unittest

from solution import solution

class TestSolution(unittest.TestCase):

    def test_case1(self):
        self.assertEqual(solution("()()"), True)
    
    def test_case2(self):
        self.assertEqual(solution("(())()"), True)

    def test_case3(self):
        self.assertEqual(solution(")()("), False)
    
    def test_case4(self):
        self.assertEqual(solution("(()("), False)

if __name__ == "__main__":
    unittest.main()