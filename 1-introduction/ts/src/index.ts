import { prog1 } from "./prog/prog1";
import { maxargs } from './maxargs';

console.log(JSON.stringify(prog1, null, 2));
console.log(`maxargs = ${maxargs(prog1)}`);