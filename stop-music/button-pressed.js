const readline = require("readline");
const { spawn } = require("node:child_process");

function delay(time) {
  return new Promise((resolve) => setTimeout(resolve, time));
}

readline.emitKeypressEvents(process.stdin);

if (process.stdin.isTTY) process.stdin.setRawMode(true);

console.log("press q to exit, or any key to print log");

process.stdin.on("keypress", async (chunk, key) => {
  if (key && key.name == "q") {
    process.exit();
  }
  if (key.name === "r") {
    const command = spawn("arecord -vv -fdat audio.wav", { detached: true });
    command.stdout.on("data", (data) => {
      console.log(data.toString());
    });
    command.stderr.on("data", (data) => {
      console.error(data.toString());
    });
    command.on("exit", (code) => {
      console.log(`Child exited with code ${code}`);
    });
    console.log("r pressed");
    await delay(3000);
    command.kill();
  }
});
