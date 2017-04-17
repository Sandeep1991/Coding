def minDistance(dist,sptSet,V):
	mini=1000000;min_index=10000
	for v in range(V):
		if sptSet[v]==0 and dist[v] <= mini:
			mini=dist[v]; min_index=v;
	print min_index, mini
	return min_index





def dijkstra(graph,src):
	dist=[1000000 for ix in range(len(graph))]
	sptSet=[0 for ixx in range(len(graph))]
	'''
	for i in range(0,len(graph)):
		dist[i]=1000000
		sptSet[i]=0
	'''
	dist[src]=0
	for cnt in range(0,len(graph)-1):
		u = minDistance(dist,sptSet,len(graph))
		sptSet[u]=1
		for v in range(0,len(graph)):
			if sptSet[v]==0 and graph[u][v] and dist[u] != 1000000 and dist[u] + graph[u][v] < dist[v]:
				dist[v] = dist[u]
	for i in range(0,len(graph)):
		print dist[i],




def main():
	t = int(raw_input())
	
	for i in range(0,t):
		graph=[]
		n,k,x,m,s = map(int,raw_input().split(' '))
		s=s-1
		graph=[[0 for xind in range(n)] for yind in range(n)]
		#print graph
		for indx in range(0,k):
			for indy in range(0,k):
				if indx != indy:
					graph[indx][indy]=x
		print graph
		for j in range(0,m):
			indx,indy,w=map(int,raw_input().split(' '))
			indx=indx-1; indy=indy-1
			graph[indx][indy]=w
			graph[indy][indx]=w
		print graph
		dijkstra(graph,s)
			

if __name__=="__main__":
	main()
