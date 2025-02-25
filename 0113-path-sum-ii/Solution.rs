// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

type OptNode = Option<Rc<RefCell<TreeNode>>>;
impl Solution {
    /// https://leetcode.com/problems/path-sum-ii/solutions/1382516/rust-dfs-solution
    pub fn path_sum(root: OptNode, target_sum: i32) -> Vec<Vec<i32>> {
        let mut answer = Vec::new();
        Self::dfs(&root, target_sum, &mut answer, &mut Vec::new());
        answer
    }

    fn dfs(node: &OptNode, target_sum: i32, answer: &mut Vec<Vec<i32>>, path: &mut Vec<i32>) {
        if let Some(n) = node {
            let n = n.borrow();
            path.push(n.val);

            if target_sum == n.val && n.left.is_none() && n.right.is_none() {
                answer.push(path.clone());
            }

            Self::dfs(&n.left, target_sum - n.val, answer, path);
            Self::dfs(&n.right, target_sum - n.val, answer, path);
            path.pop();
        }
    }
}