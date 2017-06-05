using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    public class Node
    {
        public int data;
        public Node parent, leftChild, rightChild;
        public bool Blacked;
        public Node(int _data)
        {
            data = _data;
            parent = leftChild = rightChild = null;
            Blacked = false;
        }
    }

    public class Heap
    {
        private Node[] nodes;
        private Node Root;
        private List<Node> sortedList;
        private int Counter;

        public Heap(int maxSize)
        {
            nodes = new Node[maxSize];
            sortedList = new List<Node>();
        }

        public void AddData(int d)
        {
            nodes[Counter] = new Node(d);
            LocateData(nodes[Counter]);
            Console.WriteLine("Success to add data");
            Counter++;
        }

        public void PrintAllData()
        {
            for (int i = 0; i < Counter; i++)
                Console.WriteLine(nodes[i].data);
        }

        public void PrintAllSortedData()
        {
            Sort();
            for (int i = 0; i < Counter; i++)
                Console.WriteLine(nodes[i].data);
        }

        private void SwapValuesBetweenNode(Node a, Node b)
        {
            a.data = a.data + b.data;
            b.data = a.data - b.data;
            a.data = a.data - b.data;
        }

        private void MaxHeapify(Node n)
        {
            Node curr = n;
            while(curr.parent != null)
            {
                if(curr.data > curr.parent.data)
                {
                    SwapValuesBetweenNode(curr, curr.parent);
                }
                curr = curr.parent;
            }
        }

        private void LocateData(Node n)
        {
            if (Counter == 0)
                Root = n;
            else
            {
                n.parent = nodes[(Counter - 1) / 2];
                if (nodes[(Counter - 1) / 2].leftChild == null)
                    nodes[(Counter - 1) / 2].leftChild = n;
                else
                    nodes[(Counter - 1) / 2].rightChild = n;
            }
            MaxHeapify(n);
        }

        private void SortDownHeap(Node n)
        {
            if (n == null) return;
            if (n.leftChild == null && n.rightChild == null) return;

            Node current = null;
            if(n.leftChild != null)
            {
                if(n.data < n.leftChild.data && !n.leftChild.Blacked)
                {
                    SwapValuesBetweenNode(n, n.leftChild);
                    current = n.leftChild;
                }
            }
            if (n.rightChild != null)
            {
                if (n.data < n.rightChild.data && !n.rightChild.Blacked)
                {
                    SwapValuesBetweenNode(n, n.rightChild);
                    current = n.rightChild;
                }
            }
            if(current != null)
                SortDownHeap(current);
            return;
        }

        private void Sort()
        {
            int start = Counter - 1;
            while(start > 0)
            {
                SwapValuesBetweenNode(nodes[0], nodes[start]);
                nodes[start].Blacked = true;
                sortedList.Add(nodes[start]);
                SortDownHeap(nodes[0]);
                start--;
            }
            sortedList.Add(nodes[0]);
            sortedList.Reverse();
            foreach (Node n in sortedList)
                n.Blacked = false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Heap heap = new Heap(5);
            heap.AddData(10);
            heap.AddData(15);
            heap.AddData(24);
            heap.AddData(9);
            heap.AddData(17);
            heap.PrintAllSortedData();
        }
    }
}
