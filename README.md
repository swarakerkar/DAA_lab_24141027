# DAA_lab_24141027
This repository features Design and Analysis of Algorithms lab experiments implemented with real-world applications. It covers sorting, greedy, and graph algorithms like Quick Sort, Knapsack, and Dijkstra’s, applied to practical cases such as call logs, logistics, and network design for hands-on learning.

## Title: Binary Search Algorithm  

---

## Algorithm (Step-wise Explanation):  
### 1. Start with a **sorted list** of items.  
### 2. Identify the **middle element** of the list.  
### 3. Compare the **target item** with this middle element.  
### 4. If the target matches the middle element, the search is **successful**.  
### 5. If the target is **smaller**, repeat the search in the **left half** of the list.  
### 6. If the target is **larger**, repeat the search in the **right half** of the list.  
### 7. Continue halving the list until the element is found or the list becomes **empty**.  

## Real-World Applications:  
### 1. Searching for a **contact** or name in a sorted phonebook or contact list.  
### 2. Looking up a **word** in a dictionary app.  
### 3. Finding a **record by ID** in a sorted database.  
### 4. Searching for a specific **price or product** in an e-commerce list.  
### 5. Locating a **file** in a sorted directory structure.  
### 6. Used in **autocorrect and autocomplete** algorithms to quickly match entries.  
### 7. Optimizing **game leaderboards** for rank lookups.  
### 8. Used in **version control systems** to locate commits or tags efficiently.  
### 9. Finding **timestamps or log entries** in chronologically sorted logs.  
### 10. Used in **machine learning preprocessing** to quickly identify data points in sorted arrays.  

# Experiment No. 02
## Title: Quick Sort and Merge Sort Algorithms  

---

## Quick Sort  

## Algorithm (Step-wise Explanation):  
### 1. Select one element from the list as the **pivot** (usually the first, last, or middle element).  
### 2. Rearrange elements so that all values **smaller than the pivot** are placed before it, and all **larger values** are placed after it.  
### 3. Recursively apply the same process to the **left** and **right** sublists.  
### 4. Combine the sublists once all partitions are sorted.  

## Real-World Applications:  
### 1. **E-commerce platforms** sorting product prices or ratings.  
### 2. **Database systems** for sorting query results efficiently.  
### 3. **Search engines** organizing ranked results.  
### 4. **File systems** sorting filenames or directory entries.  
### 5. **Gaming leaderboards** for ranking scores.  
### 6. **Data analytics tools** for sorting massive datasets.  
### 7. **Financial systems** sorting stock prices or transactions.  
### 8. **Memory management** in operating systems to organize data blocks.  
### 9. **Scheduling algorithms** where quick rearrangement is required.  
### 10. **Image processing** to sort pixel intensities or values.  

---

## Merge Sort  

## Algorithm (Step-wise Explanation):  
### 1. Divide the unsorted list into **two equal halves**.  
### 2. Recursively **divide** each half until each contains a single element.  
### 3. **Compare and merge** the divided elements in sorted order.  
### 4. Continue merging until the entire list is recombined and sorted.  

## Real-World Applications:  
### 1. **External sorting** for huge datasets that don’t fit in memory.  
### 2. **Merging sorted files**, like combining sorted CSVs or logs.  
### 3. **Parallel computing**, where sorting is distributed across systems.  
### 4. **Databases** to perform efficient multi-way merges in query processing.  
### 5. **Version control systems** (like Git) when merging sorted commits.  
### 6. **Email clients** sorting messages by date or sender.  
### 7. **Music apps** sorting songs by name, album, or artist.  
### 8. **Compiler design** for sorting symbols and tokens.  
### 9. **Data warehouses** for bulk sorting before aggregation.  
### 10. **Streaming data systems** for continuous merging and sorting of live inputs.  

# Experiment No. 03
## Title: Fractional Knapsack Problem  

---

## Algorithm (Step-wise Explanation):  
### 1. List all available items with their **weights** and **values**.  
### 2. Calculate the **value-to-weight ratio** for each item.  
### 3. **Sort** the items in **descending order** of their value-to-weight ratio.  
### 4. Initialize total value as **0** and remaining capacity as the **knapsack limit**.  
### 5. For each item in the sorted list:  
   - If the entire item can fit, **take it completely** and reduce the remaining capacity.  
   - If not, **take only the fraction** that fits.  
### 6. Stop when the knapsack is full or all items are considered.  
### 7. The total value obtained is the **maximum achievable value**.  

---

## Real-World Applications:  
### 1. **Cargo loading** — selecting items to maximize total value within limited weight capacity.  
### 2. **Resource allocation** — distributing limited computing resources (CPU, bandwidth, storage).  
### 3. **Portfolio management** — investing in fractional shares to maximize return under a fixed budget.  
### 4. **Cloud computing** — assigning virtual machines to servers based on efficiency ratio.  
### 5. **Project selection** — choosing profitable projects with limited manpower or budget.  
### 6. **Data compression** — optimizing data storage when memory is limited.  
### 7. **Ad placement systems** — allocating limited space/time to maximize ad revenue.  
### 8. **Supply chain optimization** — selecting shipment portions to maximize profit.  
### 9. **Disaster relief management** — packing most essential resources under weight limits.  
### 10. **Investment planning** — balancing multiple assets under capital constraints.  

# Experiment No. 04
## Title: Minimum Cost Spanning Tree (Prim’s and Kruskal’s Algorithms)  

---

## Prim’s Algorithm (Step-wise Explanation):  
### 1. Start with any vertex in the graph.  
### 2. Mark it as part of the **spanning tree**.  
### 3. From all edges connecting the tree to other vertices, **choose the edge with the smallest weight**.  
### 4. Add that edge and the new vertex to the spanning tree.  
### 5. Repeat until all vertices are included in the tree.  

---

## Kruskal’s Algorithm (Step-wise Explanation):  
### 1. List all edges of the graph and **sort them in ascending order of weight**.  
### 2. Start with an empty spanning tree.  
### 3. Add edges one by one, **starting from the smallest**, ensuring no **cycle** is formed.  
### 4. Continue until the spanning tree has **(V - 1)** edges, where V is the number of vertices.  

---

## Real-World Applications:  
### 1. **Network design** — building cost-efficient wired/wireless communication networks.  
### 2. **Road construction planning** — connecting cities with minimum total road length.  
### 3. **Electrical grid optimization** — laying cables to connect stations at minimal cost.  
### 4. **Water pipeline systems** — distributing pipelines to cover all locations efficiently.  
### 5. **Computer networks** — designing LAN or WAN topologies with least total cable usage.  
### 6. **Cluster analysis** — identifying natural groupings in datasets.  
### 7. **Transportation networks** — optimizing routes between warehouses and destinations.  
### 8. **Urban planning** — connecting housing or utilities to minimize infrastructure costs.  
### 9. **Telecom tower connections** — linking towers with minimal total distance.  
### 10. **Circuit design** — minimizing wire length while connecting all components.  

# Experiment No. 05
## Title: Optimal Merge Pattern  

---

## Algorithm (Step-wise Explanation):  
### 1. Start with **n sorted files**, each having a known size (number of records).  
### 2. Place all file sizes in a **min-heap or priority queue** to easily extract the smallest two files.  
### 3. **Remove the two smallest files** and merge them into a new file.  
### 4. Compute the **cost of merging** as the sum of their sizes.  
### 5. Insert the new file (with combined size) back into the min-heap.  
### 6. Repeat steps 3–5 until only one file remains.  
### 7. The **total cost** of all merges gives the optimal merge cost.  

---

## Real-World Applications:  
### 1. **Data storage systems** — optimizing file merges during database maintenance.  
### 2. **External sorting** — minimizing disk I/O in multi-phase sorting of large datasets.  
### 3. **Compiler design** — efficient merging of intermediate object code files.  
### 4. **Data compression** — constructing optimal Huffman codes.  
### 5. **Cloud backups** — combining incremental backup files efficiently.  
### 6. **Search engine indexing** — merging sorted posting lists for faster query retrieval.  
### 7. **Log file management** — merging time-sorted logs from multiple servers.  
### 8. **Big data frameworks (e.g., Hadoop)** — optimizing shuffle and merge operations.  
### 9. **Archival systems** — minimizing storage costs while merging old records.  
### 10. **Multimedia editing** — merging sorted media segments with minimal processing cost.  

# Experiment No. 06
## Title: Single Source Shortest Path Using Dijkstra’s Algorithm  

---

## Algorithm (Step-wise Explanation):  
### 1. **Initialize distances:** Set the distance from the source vertex to all other vertices as infinity, and to the source itself as zero.  
### 2. **Mark all vertices as unvisited.**  
### 3. **Select the vertex** with the smallest known distance that has not yet been visited.  
### 4. **Update the distances** of all its adjacent vertices by checking if the path through this vertex gives a smaller distance than the currently known one.  
### 5. **Mark the selected vertex as visited.** Once visited, its shortest distance is finalized.  
### 6. **Repeat steps 3–5** until all vertices have been visited or the smallest tentative distance among unvisited vertices is infinity.  
### 7. The algorithm outputs the **shortest path and distance** from the source to every other vertex.  

---

## Real-World Applications:  
### 1. **GPS navigation systems** — finding the shortest route between two locations.  
### 2. **Network routing protocols** — optimizing data transfer paths in routers (e.g., OSPF).  
### 3. **Public transport systems** — determining minimal travel times between stations.  
### 4. **Game AI** — pathfinding for characters or units in virtual environments.  
### 5. **Urban traffic management** — real-time re-routing based on congestion data.  
### 6. **Telecommunication networks** — minimizing signal transmission delays.  
### 7. **Emergency response systems** — planning fastest rescue or delivery routes.  
### 8. **Supply chain optimization** — finding cost-efficient delivery or distribution paths.  
### 9. **Robotics navigation** — helping autonomous robots find efficient movement paths.  
### 10. **Social network analysis** — finding the shortest connection chain between two users.  

# Experiment No. 07
## Title: Optimal Binary Search Trees using Dynamic Programming  

---

## Algorithm (Step-wise Explanation):  
### 1. **Understand the Problem:** Identify the set of keys to be stored in the BST along with their access probabilities (how often each key is searched).  
### 2. **Initialize Tables:** Create two tables: one for storing the cost of subtrees and another for storing the root of optimal subtrees.  
### 3. **Single Key Trees:** Fill the tables for subtrees containing only one key, as their cost is simply the probability of that key.  
### 4. **Build Larger Subtrees:** Gradually consider subtrees of increasing size (two keys, three keys, … up to all keys).  
### 5. **Compute Cost for Subtrees:** For each possible root in the current subtree, calculate the total cost as the sum of:  
   - The cost of the left subtree  
   - The cost of the right subtree  
   - The sum of probabilities of all keys in the subtree (since each access passes through the root)  
### 6. **Select Optimal Root:** Choose the root that gives the minimum total cost for the current subtree and store it in the table.  
### 7. **Repeat:** Continue this process until the cost of the subtree containing all keys is calculated.  
### 8. **Construct the Tree (Optional):** Use the root table to reconstruct the optimal BST if required.  

---

## Real-World Applications:  
### 1. **Database Indexing:** Optimizing search trees for frequently queried database records.  
### 2. **Compiler Design:** Efficient symbol table implementations.  
### 3. **Spell Checking:** Fast lookup of words in dictionaries where certain words are searched more frequently.  
### 4. **Autocorrect/Autocomplete Systems:** Optimizing searches for predictive text suggestions.  
### 5. **Data Compression:** Using optimal BSTs in coding algorithms for faster access.  
### 6. **Decision Support Systems:** Representing decision processes where some outcomes are more probable.  
### 7. **Routing Tables in Networks:** Optimizing lookup times for frequently accessed routes.  
### 8. **Search Engines:** Optimizing access to frequently searched terms or keywords.  

# Experiment No. 08
## Title: All-Pairs Shortest Paths Problem using Floyd's Algorithm  

---

## Algorithm (Step-wise Explanation):  
### 1. **Understand the Problem:** You have a weighted graph (directed or undirected) with n vertices, and you want to find the shortest distance between every pair of vertices.  
### 2. **Initialize Distance Table:** Create a matrix to store distances between all pairs of vertices. Set the distance from a vertex to itself as zero and distances between directly connected vertices as their edge weights. For vertices that are not directly connected, set the distance as infinity.  
### 3. **Iterate Over Intermediate Vertices:** For each vertex in the graph, consider it as an intermediate point that might be part of the shortest path between two other vertices.  
### 4. **Update Distances:** For every pair of vertices (i, j), check if passing through the intermediate vertex provides a shorter path than the current known distance. If yes, update the distance in the table.  
### 5. **Repeat for All Vertices:** Continue this process until each vertex has been considered as an intermediate point.  
### 6. **Final Distance Matrix:** After all iterations, the distance table will contain the shortest distances between every pair of vertices.  
### 7. **(Optional) Construct Path:** If required, maintain a predecessor table to reconstruct the shortest paths.  

---

## Real-World Applications:  
### 1. **Network Routing:** Finding the shortest paths in communication or computer networks.  
### 2. **Map and Navigation Systems:** Determining shortest routes between all locations in a city or region.  
### 3. **Traffic Management:** Optimizing traffic flow by analyzing shortest paths between junctions.  
### 4. **Telecommunication Networks:** Minimizing latency in data transmission.  
### 5. **Airline Flight Planning:** Finding minimum-cost or shortest-time connections between airports.  
### 6. **Urban Planning:** Planning efficient pathways for utilities, roads, and transportation networks.  
### 7. **Social Network Analysis:** Calculating closeness and connectivity between users.  
### 8. **Robotics:** Path planning for multiple robots in a shared workspace.  

# Experiment No. 09
## Title: Single Source Shortest Path Problem  

---

## Algorithm (Step-wise Explanation):  
### 1. **Understand the Problem:** You have a weighted graph and want to find the shortest distance from a single source vertex to all other vertices.  
### 2. **Initialize Distances:** Set the distance from the source vertex to itself as zero and the distances to all other vertices as infinity.  
### 3. **Mark Vertices as Unvisited:** Keep track of which vertices have been visited. Initially, all vertices are unvisited.  
### 4. **Select the Minimum Distance Vertex:** Choose the unvisited vertex with the smallest current distance from the source.  
### 5. **Update Neighboring Distances:** For each unvisited neighbor of the selected vertex, check if the path through the selected vertex offers a shorter distance. If yes, update the distance.  
### 6. **Mark Vertex as Visited:** Once a vertex’s neighbors have been updated, mark it as visited.  
### 7. **Repeat:** Continue selecting the next unvisited vertex with the minimum distance and updating neighbors until all vertices are visited.  
### 8. **Final Distances:** After all vertices are visited, you have the shortest distances from the source to every other vertex.  

---

## Real-World Applications:  
### 1. **GPS Navigation:** Finding the fastest route from a starting location to multiple destinations.  
### 2. **Network Routing:** Determining the most efficient path from a source node to all other nodes in a network.  
### 3. **Telecommunication Networks:** Minimizing transmission delays from a central server to multiple clients.  
### 4. **Logistics and Delivery Systems:** Optimizing delivery paths from a warehouse to various locations.  
### 5. **Urban Transport Planning:** Calculating shortest paths from a hub to all bus/train stations.  
### 6. **Robotics:** Path planning for a robot from a starting point to multiple targets.  
### 7. **Video Games:** AI navigation for characters to move efficiently from a spawn point to other points on a map.  
### 8. **Emergency Response:** Determining fastest routes from a hospital or fire station to multiple incident locations.  

# Experiment No. 10
## Title: 8-Queens Problem using Backtracking  

---

## Algorithm (Step-wise Explanation):  
### 1. **Understand the Problem:** Place 8 queens on an 8×8 chessboard so that no two queens threaten each other (i.e., no two queens share the same row, column, or diagonal).  
### 2. **Start from First Row:** Place a queen in the first row and the first column.  
### 3. **Check Safety:** Before placing a queen in any cell, check if it is safe—i.e., no other queen is in the same column, row, or diagonal.  
### 4. **Place Queen:** If the cell is safe, place the queen there.  
### 5. **Move to Next Row:** Recursively try to place a queen in the next row following the same procedure.  
### 6. **Backtrack if Needed:** If no safe cell is found in a row, remove the last placed queen (backtrack) and try the next possible cell in the previous row.  
### 7. **Repeat:** Continue this process until all queens are placed on the board safely.  
### 8. **Store/Print Solution:** Once all 8 queens are placed safely, record the solution. Continue to find all possible solutions by backtracking.  

---

## Real-World Applications:  
### 1. **Constraint Satisfaction Problems:** Used in scheduling, assignment, and allocation problems.  
### 2. **Puzzle Solving:** Solving other board-based or logic puzzles.  
### 3. **Resource Allocation:** Assigning resources without conflict (e.g., exam scheduling).  
### 4. **AI Problem Solving:** Demonstrating recursive and backtracking techniques in AI.  
### 5. **Computer Games:** Designing algorithms for puzzle-based games.  
### 6. **Robotics:** Path planning with constraints to avoid collisions.  
### 7. **Network Optimization:** Placing servers, routers, or antennas without interference.  
### 8. **Software Testing:** Generating test cases under multiple constraints.  
