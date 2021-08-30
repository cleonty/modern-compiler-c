import { prog1 } from "./prog/prog1";
import { maxargs } from './maxargs';
import { interp } from "./interp";

console.log(JSON.stringify(prog1, null, 2));
console.log(`maxargs = ${maxargs(prog1)}`);
console.log(interp(prog1, {}));