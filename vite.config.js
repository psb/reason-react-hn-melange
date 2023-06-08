import react from "@vitejs/plugin-react";
import resolve from "@rollup/plugin-node-resolve";

export default {
  plugins: [react(), resolve()],
};
