impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();

        for i in 0..nums.len() {
            let complement = target - nums[i];
            for j in (i + 1)..nums.len() {
                if complement == nums[j] {
                    result.push(i as i32);
                    result.push(j as i32);
                    return result; // Return early when found
                }
            }
        }

        result
    }
}
