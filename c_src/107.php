/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {


    public $ans = [];
    /**
     * @param TreeNode $root
     * @return Integer[][]
     */
    function levelOrderBottom($root)
    {
        $this->traversal($root, 0);
        var_export(array_reverse($this->ans));
        return array_reverse($this->ans);
    }

    function traversal($node, int $level)
    {
        if ($node == null) {
            return;
        }
        $this->ans[$level][] = $node->val;
        $this->traversal($node->left, $level + 1);
        $this->traversal($node->right, $level + 1);
    }
}