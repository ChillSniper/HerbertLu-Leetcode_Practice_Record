package problems_set;
// import java.util.*;
// class TaskManager {

//     Map<Integer, Integer> task_to_user = new HashMap<>();
//     Map<Integer, Integer> task_to_prio = new HashMap<>();
//     TreeMap<Integer, TreeSet<Integer>> prio_to_task = new TreeMap<>(); 

//     public TaskManager(List<List<Integer>> tasks) {
//         // 这个破题纯属是折腾人
//         // 怎么设计呢
//         // taskId -> userId
//         // priority -> taskId
//         // [userid, taskid, priority]
//         int n = tasks.size();
//         for (int i = 0;i < n;i ++) {
//             int userId = tasks.get(i).get(0), taskId = tasks.get(i).get(1), priority = tasks.get(i).get(2);
            
//             add(userId, taskId, priority);
//         }
//     }
    
//     public void add(int userId, int taskId, int priority) {
//         task_to_user.put(taskId, userId);
//         if(!prio_to_task.containsKey(priority)) {
//             prio_to_task.put(priority, new TreeSet<>());
//         }
//         prio_to_task.get(priority).add(taskId);
//         task_to_prio.put(taskId, priority);
//     }
    
//     public void edit(int taskId, int newPriority) {
//         int oldprio = task_to_prio.get(taskId);
//         task_to_prio.put(taskId, newPriority);
//         prio_to_task.get(oldprio).remove(taskId);
//         if(prio_to_task.get(oldprio).isEmpty()) {
//             prio_to_task.remove(oldprio);
//         }
//         if(!prio_to_task.containsKey(newPriority)) {
//             prio_to_task.put(newPriority, new TreeSet<>());
//         }
//         prio_to_task.get(newPriority).add(taskId);
//     }
    
//     public void rmv(int taskId) {
//         int del_prio = task_to_prio.get(taskId);
//         task_to_user.remove(taskId);
//         task_to_prio.remove(taskId);
//         prio_to_task.get(del_prio).remove(taskId);
//         if(prio_to_task.get(del_prio).isEmpty()) {
//             prio_to_task.remove(del_prio);
//         }
//     }
    
//     public int execTop() {
//         if(prio_to_task.isEmpty()) {
//             return -1;
//         }
//         int lastKey = prio_to_task.lastKey();
//         int target_taskid = prio_to_task.get(lastKey).last();
//         int ans = task_to_user.get(target_taskid);
//         rmv(target_taskid);
//         return ans;
//     }
// }

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */
import java.util.*;
class TaskManager {

    // test the solution: Lazy delete map.

    final private Map<Integer, int[]> latest = new HashMap<>();
    final private PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] != b[0] ? b[0] - a[0] :b[1] - a[1]);

    // [userid, taskid, priority]
    public TaskManager(List<List<Integer>> tasks) {
        for (List<Integer> t : tasks) {
            add(t.get(0), t.get(1), t.get(2));
        }
    }
    
    final void add(int userId, int taskId, int priority) {
        latest.put(taskId, new int[]{userId, priority});
        pq.add(new int[]{priority, taskId, userId});
    }
    
    public void edit(int taskId, int newPriority) {
        int userId = latest.get(taskId)[0];
        add(userId, taskId, newPriority);
    }
    
    public void rmv(int taskId) {
        // here is important
        latest.put(taskId, new int[]{-1, -1});
    }
    
    public int execTop() {
        while(!pq.isEmpty()) {
            int priority = pq.peek()[0], taskId = pq.peek()[1], userId = pq.peek()[2];
            pq.poll();
            rmv(taskId);
            if(priority == latest.get(taskId)[1] && userId == latest.get(taskId)[0]) {
                return userId;
            }
        }
        return -1;
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */