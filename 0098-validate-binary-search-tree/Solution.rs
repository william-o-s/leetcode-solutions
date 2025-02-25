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
    pub fn is_valid_bst(root: OptNode) -> bool {
        // https://leetcode.com/problems/validate-binary-search-tree/solutions/2409078/rust-yars-yet-another-recursive-solution
        Self::is_valid(&root, i32::MIN as i64 - 1, i32::MAX as i64 + 1)
    }

    fn is_valid(node: &OptNode, minimum: i64, maximum: i64) -> bool {
        match node.as_ref() {
            None => true,
            Some(n) => {
                let b = n.borrow();

                (b.val as i64) > minimum
                && (b.val as i64) < maximum
                && Self::is_valid(&b.left, minimum, b.val as i64)
                && Self::is_valid(&b.right, b.val as i64, maximum)
            }
        }
    }
}