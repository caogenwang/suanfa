
//构造数组的MaxTree
public class Code_02_MaxTree {

    //二叉树结点的定义如下
    public static class Node {
        public int value;
        public Node left;
        public Node right;

        //结点的初始化
        public Node(int data) {
            this.value = data;
        }
    }

    //构造数组的MaxTree函数
    public static Node getMaxTree(int[] arr) {
        Node[] nArr = new Node[arr.length];  //存放二叉树结点的数组
        for (int i = 0; i != arr.length; i++) {
            nArr[i] = new Node(arr[i]);
        }
        Stack<Node> stack = new Stack<Node>();//利用栈找出左右边第一个比自身大的数
        HashMap<Node, Node> lBigMap = new HashMap<Node, Node>();
        HashMap<Node, Node> rBigMap = new HashMap<Node, Node>();
        //从第一个开始
        // 找出所有数，左边第一个比自身大的数,键值对就是本身节点和左边第一个比自身大的数
        for (int i = 0; i != nArr.length; i++) {
            Node curNode = nArr[i];
            while ((!stack.isEmpty()) && stack.peek().value < curNode.value) {
                popStackSetMap(stack, lBigMap);//栈的一系列操作
            }
            stack.push(curNode);
        }
        while (!stack.isEmpty()) {
            popStackSetMap(stack, lBigMap);
        }
        //从最后一个开始
        // 找出所有数，右边第一个比自身大的数，键值对就是本身节点和右边第一个比自身大的数
        for (int i = nArr.length - 1; i != -1; i--) {
            Node curNode = nArr[i];
            while ((!stack.isEmpty()) && stack.peek().value < curNode.value) {
                popStackSetMap(stack, rBigMap);//栈的一系列操作
            }
            stack.push(curNode);
        }
        while (!stack.isEmpty()) {
            popStackSetMap(stack, rBigMap);
        }
        Node head = null; //声明头结点
        for (int i = 0; i != nArr.length; i++) {//遍历所有的节点
            Node curNode = nArr[i];
            Node left = lBigMap.get(curNode);
            Node right = rBigMap.get(curNode);
            //左右都空，证明他是最大的头节点
            if (left == null && right == null) {
                head = curNode;
            } else if (left == null) {//左为空，就串在右的底下
                if (right.left == null) {//从左到右
                    right.left = curNode;
                } else {
                    right.right = curNode;
                }
            } else if (right == null) {//右为空，就串在左的底下
                if (left.left == null) {//从左到右
                    left.left = curNode;
                } else {
                    left.right = curNode;
                }
            } else {
                //选择左右较小的数为父节点
                Node parent = left.value < right.value ? left : right;
                if (parent.left == null) {//从左到右
                    parent.left = curNode;
                } else {
                    parent.right = curNode;
                }
            }
        }
        return head;
    }

    //栈的一系列操作
    public static void popStackSetMap(Stack<Node> stack, HashMap<Node, Node> map) {
        Node popNode = stack.pop();

        if (stack.isEmpty()) {
            map.put(popNode, null);
        } else {
            map.put(popNode, stack.peek()); //构造二叉树操作
        }

    }

    //二叉树的先序遍历
    public static void printPreOrder(Node head) {
        if (head == null) { return; }
        System.out.print(head.value + " ");
        printPreOrder(head.left);  //递归调用遍历二叉树
        printPreOrder(head.right);
    }

    //二叉树的中序遍历
    public static void printInOrder(Node head) {
        if (head == null) { return; }
        printInOrder(head.left);
        System.out.print(head.value + " ");
        printInOrder(head.right);
    }


    public static void main(String[] args) {
        int[] arr = {3, 4, 5, 1, 2};
        Node head = getMaxTree(arr);
        printPreOrder(head);
        System.out.println();
        printInOrder(head);
    }
}