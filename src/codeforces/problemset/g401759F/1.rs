use std::collections::BTreeMap;
use std::io::{self, BufRead};

fn query(pos: i32, total: i32, threshold: i32, mp: &BTreeMap<i32, i32>) -> i32 {
    if let Some(&value) = mp.get(&pos) {
        return value;
    }
    if pos == 0 || pos == total + 1 {
        return 1;
    }
    if pos <= threshold {
        return 1;
    }
    return 0;
}

fn main() {
    let stdin = io::stdin();
    let mut input = stdin.lock();

    let mut buffer = String::new();
    input.read_line(&mut buffer).unwrap();
    let t: i32 = buffer.trim().parse().unwrap();

    for case_number in 1..=t {
        println!("Case {}:", case_number);
        let mut mp: BTreeMap<i32, i32> = BTreeMap::new();

        buffer.clear();
        input.read_line(&mut buffer).unwrap();
        let mut nums = buffer
            .split_whitespace()
            .map(|x| x.parse::<i32>().unwrap())
            .collect::<Vec<i32>>();

        let (mut n, mut k, mut q) = (nums[0], nums[1], nums[2]);
        let mut ans = 1;

        while q > 0 {
            buffer.clear();
            input.read_line(&mut buffer).unwrap();
            nums = buffer
                .split_whitespace()
                .map(|x| x.parse::<i32>().unwrap())
                .collect::<Vec<i32>>();

            let (x, y) = (nums[0], nums[1]);

            let cx = query(x - 1, n, k, &mp) + query(x + 1, n, k, &mp);
            if cx == 0 {
                ans -= 1;
            } else if cx == 2 {
                ans += 1;
            }
            mp.insert(x, 0);

            let cy = query(y - 1, n, k, &mp) + query(y + 1, n, k, &mp);
            if cy == 0 {
                ans += 1;
            } else if cy == 2 {
                ans -= 1;
            }
            mp.insert(y, 1);

            println!("{}", ans);
            q -= 1;
        }
    }
}
