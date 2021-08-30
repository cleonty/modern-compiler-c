export interface Tree {
  key: string;
  left?: Tree;
  right?: Tree;
  binding: any;
}

export function insert(key: string, binding: any, tree?: Tree): Tree {
  if (!tree) {
    return { key, binding };
  }
  const compareRes = key.localeCompare(tree.key);
  if (compareRes < 0) {
    return { key: tree.key, binding: tree.binding, left: insert(key, binding, tree.left), right: tree.right };
  } else if (compareRes > 0) {
    return { key: tree.key, binding: tree.binding, left: tree.left, right: insert(key, binding, tree.right) };
  } else {
    return { key: tree.key, binding: binding, left: tree.left, right: tree.right };
  }
}

export function search(key: string, tree?: Tree): boolean {
  if (!tree) {
    return false;
  }
  const compareRes = key.localeCompare(tree.key);
  if (compareRes === 0) {
    return true;
  }
  if (compareRes < 0) {
    return search(key, tree.left);
  }
  return search(key, tree.right);
}

export function lookup (key: string, tree?: Tree): any {
  if (!tree) {
    return;
  }
  const compareRes = key.localeCompare(tree.key);
  if (compareRes === 0) {
    return tree.binding;
  }
  if (compareRes < 0) {
    return lookup(key, tree.left);
  }
  return lookup(key, tree.right);
}