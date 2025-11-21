const start = process.hrtime.bigint()

console.log("Running benchmark for loop")
let sum = 0n;
for (let i = 0n; i < 1_000_000_000n; i++) {
  sum += i;
}

const end = process.hrtime.bigint();

const elapsed = Number(end - start) / 1e9;

console.log(`Time: ${elapsed} seconds`);
