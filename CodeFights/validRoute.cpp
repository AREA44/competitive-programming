// Consider a lonely Uber driver working in a big city. He has N requests that he has to grant exactly in the given order. The route is already mapped out for him and we can assume that he picks up a new passenger at exactly the same spot where he drops off the previous one.
// Each request consists of two numbers: the time by which the rider will be ready to go, and the time by which the rider will cancel the request if the car is not there. This means that if the driver arrives too early, he'll have to wait to pick up the passenger. If he arrives too late, the ride will be canceled.
// Knowing the requests' details and the time it takes to travel from one to the next, determine the minimum amount of time the given route will take, or return -1 if it is impossible to service all the requests.
// Note that as you're given the driver's daily plan, the answer is smaller than the number of seconds in a day (24 * 60 * 60 = 86400).
// Example
// * For travelTimes = [500, 500], readyTimes = [1000, 3000] and cancelTimes = [2000, 4000], the output should be
// validRoute(travelTimes, readyTimes, cancelTimes) = 1500.
// The best plan the Uber driver can follow is this one:
// 1. Pick up the first rider at 2000 (he/she cannot do it later because cancelTimes[0] = 2000).
// 2. Spend 500 seconds delivering the first rider to the desired location.
// 3. Wait for 500 seconds until the second rider is ready to go.
// 4. Spend 500 seconds delivering the second rider to the desired location.

// * For travelTimes = [1, 1, 1], readyTimes = [3000, 2000, 5000] and cancelTimes = [3500, 3000, 6000], the output should be
// validRoute(travelTimes, readyTimes, cancelTimes) = -1.
//Since the driver has to grant the requests exactly in the given order, he has to start with the first one. There is no way for him to make it in time for the second rider.

int validRoute(std::vector<int> travelTimes,
               std::vector<int> readyTimes, std::vector<int> cancelTimes) {

  int earliestStartTime = 0;
  int latestStartTime = 24 * 60 * 60;
  int totalWorkTime = 0;
  for (int i = 0; i < readyTimes.size(); i++) {
    if (earliestStartTime + totalWorkTime > cancelTimes[i]) {
      return -1;
    }
    latestStartTime = std::min(latestStartTime,
        cancelTimes[i] - totalWorkTime);
    if (latestStartTime + totalWorkTime < readyTimes[i]) {
      totalWorkTime = readyTimes[i] - latestStartTime;
    }
    earliestStartTime = std::max(earliestStartTime,
        readyTimes[i] - totalWorkTime);

    totalWorkTime += travelTimes[i];
  }

  return totalWorkTime;
}
