{
  description = "Raylib C Development Environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
    let
      system = "x86_64-linux"; # Adjust this to your architecture if needed (e.g., aarch64-linux)
      pkgs = import nixpkgs { inherit system; };
    in {
      devShells.${system}.default = pkgs.mkShell {
        # Packages available in your shell
        packages = with pkgs; [
          gcc             # Compiler
          gnumake         # Build tool
          pkg-config      # Helper for finding libraries
          raylib          # The library itself
        ];

        # Environment variables or setup logic
        shellHook = ''
          echo "Raylib development environment loaded!"
        '';
      };
    };
}
