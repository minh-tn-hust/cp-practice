import java.util.*;

class Server {
    int order;
    int weight;
    int timeAtIdle;
    Server(int weight, int order) {
        this.order = order;
        this.weight = weight;
    }

    void processTask(int duration) {
        timeAtIdle += duration;
    }
}

class SelectingPriority implements Comparator<Server> {
    public int compare(Server a, Server b) {
        if (a.weight != b.weight) {
            return a.weight - b.weight;
        }
        return a.order - b.order;
    }
}

class IdlingPriority implements Comparator<Server> {
    public int compare(Server a, Server b) {
        return a.timeAtIdle - b.timeAtIdle;
    }
}

class Solution {
    PriorityQueue<Server> idleServers = new PriorityQueue<>(new SelectingPriority());
    PriorityQueue<Server> processingServers = new PriorityQueue<>(new IdlingPriority());

    public int[] assignTasks(int[] servers, int[] tasks) {
        initIdleServers(servers);    

        int taskIndex = 0;
        int time = 0;
        int taskForServer[] = new int[tasks.length];

        while (taskIndex < tasks.length) {
            transformIdlingServersIntoReadyOnesAt(time);

            int taskAlreadyInQueue = Math.min(time + 1, tasks.length) - taskIndex;

            List<Server> selectedServers = getSelectedServerFromIdling(taskAlreadyInQueue);
            if (isAllInProcessing(selectedServers)) {
                time = getNearestIdleServerTime();
                continue;
            }

            for (Server nextProcessingServer : selectedServers) {
                nextProcessingServer.timeAtIdle = time + tasks[taskIndex];
                processingServers.add(nextProcessingServer);
                taskForServer[taskIndex] = nextProcessingServer.order;
                taskIndex++;
            }

            time++;
        }

        return taskForServer;
    }

    void initIdleServers(int [] servers) {
        for (int order = 0; order < servers.length; order++) {
            int weight = servers[order];
            idleServers.add(new Server(weight, order));
        }
    }

    void transformIdlingServersIntoReadyOnesAt(int time) {
        List<Server> nextIdleServers = getIdlingServerFromProcessing(time);
        for (Server idleServer : nextIdleServers) {
            idleServers.add(idleServer);
        }
    }

    List<Server> getIdlingServerFromProcessing(int atTime) {
        List<Server> idlingServers = new ArrayList<>();
        while (!processingServers.isEmpty()) {
            Server server = processingServers.peek();

            if (isIdling(server, atTime)) {
                idlingServers.add(server);
                processingServers.poll();
            } else {
                break;
            }
        }

        return idlingServers;
    }

    boolean isAllInProcessing(List<Server> selectedServers) {
        return (selectedServers.size() == 0);
    }

    boolean isIdling(Server server, int atTime) {
        return server.timeAtIdle <= atTime;
    }

    List<Server> getSelectedServerFromIdling(int numRequireServer) {
        List<Server> selectedServers = new ArrayList<>();

        while (!idleServers.isEmpty() && numRequireServer > 0) {
            Server server = idleServers.peek();
            idleServers.poll();
            selectedServers.add(server);
            numRequireServer--;
        }

        return selectedServers;
    } 

    int getNearestIdleServerTime() {
        return processingServers.peek().timeAtIdle;
    }
}