package algoclass;
import java.util.*;

public class Graph {
	class Pair{
		int curr;
		int prev;
		Pair(int curr,int prev){
			this.curr=curr;
			this.prev=prev;
		}
	}
	private class Node{
		int prev;//used only for prims algo keeping track of previous node should not have used it could have created seperate datastructure
		int v;
		int weight;
		Node(int v,int weight){
			this.v=v;
			this.weight=weight;
		}
		Node(int v,int weight,int prev){
			this.v=v;
			this.weight=weight;
			this.prev=prev;
		}
		
	}
	HashMap<Integer,ArrayList<Node>> vert;
Graph(){
	this.vert=new HashMap<Integer,ArrayList<Node>>();
}

public void addEdge(int u,int v,int weight) {
if(this.vert.containsKey(u)) {
	this.vert.get(u).add(new Node(v,weight));
}
else {
	this.vert.put(u, new ArrayList<Node>());
	this.vert.get(u).add(new Node(v,weight));
}
if(this.vert.containsKey(v)) {
	this.vert.get(v).add(new Node(u,weight));
}
else {
	this.vert.put(v, new ArrayList<Node>());
	this.vert.get(v).add(new Node(u,weight));
}
}

public void print() {
	this.vert.forEach((key,value)->{
		System.out.println(key+" "+value);
	});
}
public void primAlgo(int startnode) {
	PriorityQueue<Node> pq=new PriorityQueue<Node>((temp1,temp2)->{
		if(temp1.weight>temp2.weight) {
			return 1;
		}
		else {
			return -1;
		}
	});
	HashSet<Integer> visited=new HashSet<Integer>();
	ArrayList<Pair> mstedges=new ArrayList<Pair>();
	pq.add(new Node(startnode,0,-1));
	int mstweight=0;
	while(!pq.isEmpty()) {
		Node curr=pq.poll();
		System.out.println(curr.v+" "+curr.prev);
		if(visited.contains(curr.v)) {
			continue;
		}
		else {
			mstweight+=curr.weight;
			mstedges.add(new Pair(curr.v,curr.prev));
//			mstedges.put(curr.v,curr.prev);
			visited.add(curr.v);
			ArrayList<Node> alladjacentnodes=this.vert.get(curr.v);
			alladjacentnodes.forEach((eachnode)->{
				pq.add(new Node(eachnode.v,eachnode.weight,curr.v));
			});
		}
	}
	mstedges.forEach((pair)->{
		System.out.print(pair.prev+"<="+pair.curr+"  ");
	});
	System.out.println(mstweight);
}

}
