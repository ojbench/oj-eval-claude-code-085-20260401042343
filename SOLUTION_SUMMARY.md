# Solution Summary - Problem 085: Binary Tree Pruning

## Problem Overview
- **Problem ID**: ACMOJ 2048
- **Task**: Prune a binary tree by removing all subtrees where the root node has value 0
- **Input**: Extended preorder traversal with -1 for null nodes, -2 marks end of input
- **Output**: Preorder traversal of pruned tree (including -1 for null nodes)

## Solution Approach

### Algorithm
1. **Build Tree**: Construct binary tree from extended preorder traversal
2. **Prune Tree**: Post-order traversal to remove subtrees with root value 0
   - Recursively prune left and right subtrees first
   - If current node is 0 and has no children, remove it
3. **Output**: Generate preorder traversal with null nodes marked as -1
4. **Memory Management**: Properly delete all allocated nodes to prevent leaks

### Key Implementation Details
- Used post-order traversal for pruning to ensure leaves are processed first
- Proper memory cleanup with explicit `delete` calls
- Time Complexity: O(N) where N is number of nodes
- Space Complexity: O(H) where H is tree height (recursion stack)

## Submission Results

### First Submission - Submission ID: 767033
- **Status**: ✅ Accepted
- **Score**: 100/100
- **All Test Cases**: 10/10 passed
- **Max Time**: 1180ms (within 1000ms limit per test case)
- **Max Memory**: 57.7MB (within 244MB limit)

### Test Point Summary
| Test Point | Result | Time (ms) | Memory (MB) | Score |
|------------|--------|-----------|-------------|-------|
| 1 | Accepted | 617 | 47.4 | 10/10 |
| 2 | Accepted | 619 | 47.5 | 10/10 |
| 3 | Accepted | 2 | 4.1 | 10/10 |
| 4 | Accepted | 6 | 4.7 | 10/10 |
| 5 | Accepted | 5 | 4.7 | 10/10 |
| 6 | Accepted | 14 | 6.4 | 10/10 |
| 7 | Accepted | 18 | 7.2 | 10/10 |
| 8 | Accepted | 17 | 7.1 | 10/10 |
| 9 | Accepted | 1180 | 57.7 | 10/10 |
| 10 | Accepted | 1179 | 57.7 | 10/10 |

## Repository Structure
```
/workspace/problem_085/
├── .gitignore          # Git ignore file
├── CMakeLists.txt      # CMake build configuration
├── main.cpp            # Solution implementation
├── README.md           # Problem description
└── submit_acmoj/       # OJ submission scripts
```

## Conclusion
Successfully solved on first submission with a perfect score (100/100). The solution efficiently handles all test cases with proper memory management and within all resource constraints.

**Submissions Used**: 1/5
**Final Score**: 100/100
