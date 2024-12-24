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
    pub fn inorder_traversal(root: OptNode) -> Vec<i32> {
        let mut path = Vec::new();
        Self::dfs(&root, &mut path);
        path
    }

    fn dfs(node: &OptNode, path: &mut Vec<i32>) {
        if let Some(node) = node {
            let node = node.borrow();
            Self::dfs(&node.left, path);
            path.push(node.val);
            Self::dfs(&node.right, path);
        }
    }
}