// There is a queue at the gates of a shopping center. A camera on the gates registers the exact time (with a minutes precision) when a new person joins the back of the queue and the shopping center is letting one person in at a time every 5 minutes.
// To evaluate the current process, you want to save a photo of the queue at the moment when it has the largest number of people in it (if there are several such moments, you would choose the earliest one). The camera doesn't have good quality, so the only thing that will be visible on the photo are the colors of people's shirts.
// Given the arrival times and shirt colors determine what the photo will look like.
// In a situation where a person is supposed to be entering the shopping center in the exact same minute when another person is joining the back of the queue you can assume that the joining happens a little later.
// Example
// * For times = [0, 3, 5, 7] and colors = ["r", "g", "b", "w"], the output should be
// queuePhoto(times, colors) = "gbw".

// The states of the queue will be as follows:

// (minute 0)"" -> 
// (minute 0)"r" - "r" arrives -> 
// (minute 3)"rg" - "g" arrives -> 
// (minute 5)"g" - "r" enters the center -> 
// (minute 5)"gb" - "b" arrives -> 
// (minute 7)"gbw" - "w" arrives -> 
// (minute 10)"bw" - "g" enters the center -> 
// (minute 15)"w" - "b" enters the center -> 
// (minute 20)"" - "w" enters the center 

// Check out the image below for better understanding: https://cloud.githubusercontent.com/assets/16760489/20495651/892c0ee0-b054-11e6-83be-d378a17b46cd.png

std::string queuePhoto(std::vector<int> times, std::vector<char> colors) {
    int next = 0,
        queueStart = 0,
        queueEnd = 0,
        indexLeft = -1,
        res = 0,
        lastOut = 0;

    while (next < times.size()) {
        if (queueStart == queueEnd || lastOut + 5 > times[next]) {
            lastOut = times[next] / 5 * 5;
            queueEnd++;
            next++;
            if (queueEnd - queueStart > res) {
                res = queueEnd - queueStart;
                indexLeft = queueStart;
            }
        } else {
            lastOut += 5;
            queueStart++;
        }
    }

    string resStr = "";
    for (int i = indexLeft; i < indexLeft + res; i++) {
        resStr += colors[i];
    }
    return resStr;
}
