import LinkedList.DoubleLinkedList;
import LinkedList.SingleLinkedList;
import BinaryTree.tree;
public class App {
    public static void main(String[] args) throws Exception {
        DoubleLinkedList<Integer> mylist = new DoubleLinkedList<>();
        System.out.println("After insert at beginning numbers : 1, 2, 3, 4 and 5");
        mylist.inset_at_beginning(1);
        mylist.inset_at_beginning(2);
        mylist.inset_at_beginning(3);
        mylist.inset_at_beginning(4);
        mylist.inset_at_beginning(5);
        mylist.traversal();

        System.out.println("After insert at last numbers: 6, 7, 8");
        mylist.insert_at_last(6);
        mylist.insert_at_last(7);
        mylist.insert_at_last(8);
        mylist.traversal();

        System.out.println("After delete number 6");
        mylist.delete(6);
        mylist.traversal();
    
        System.out.println("After delete the head");
        mylist.delete(5);
        mylist.traversal();

        System.out.println("After delete the tail");
        mylist.delete(8);
        mylist.traversal();

        tree tree = new tree();

        tree.insert(8);
        tree.insert(2);
        tree.insert(3);
        tree.insert(1);
        tree.insert(9);
        tree.insert(75);
        tree.insert(5);
        
        tree.search_recursive(3);

        tree.print_preorder();
        tree.print_inorder();
        tree.print_postorder();

        tree.delete(3);

        tree.print_preorder();
                

    }
}
